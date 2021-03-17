# Prometheus Up & Running Book Summary

## What is Prometheus

Four ways of reducing data volume:
- Profiling
- Tracing
- Logging
- Metrics

### Prometheus Architecture

Componentes of Prometheus architecture:
- Client libraries
- Exporter
- Service discovery
- Scraping
- Storage
- Dashboard
- Recording rules and alerts
- Alert management

## Instrumentation
 Instrumentation is the use of a library in an application's code base in order to expose and update metrics about it for a Prometheus instance to scrape.


### The Gauge
- Gauges are a snapshot of some current state. 
- Examples of gauges include:
    - the number of items in the queue
    - memory usage of a cache
    - number of active threads
    - the last time a record was processed

- Gauges have three main methods: inc, dec and set.

### The Histogram
- A histogram is a set of buckets, such as 1ms, 2ms, 5ms, 10ms, that track the numbers of events that fall into each bucket. The histogram_quantile PromQL function can calculate a quantile from the buckets.

### Unit Testing Instrumentation
A sample code snippet for unit testing a prometheus counter.

<details>
<summary>unit_test.go</summary>

```
package main

import (
	"testing"

	"github.com/prometheus/client_golang/prometheus"
	dto "github.com/prometheus/client_model/go"
	"github.com/stretchr/testify/assert"
)

var (
	foos = prometheus.NewCounter(prometheus.CounterOpts{
		Name: "foos_total",
		Help: "The number of foo calls",
	})
	reg = prometheus.NewRegistry()
)

func Foo() {
	foos.Inc()
}

func getMetricValue(col prometheus.Collector) float64 {
	c := make(chan prometheus.Metric, 1) // 1 for metric with no vector
	col.Collect(c)                       // collect current metric value into the channel
	m := dto.Metric{}
	_ = (<-c).Write(&m) // read metric value from the channel
	return *m.Counter.Value
}

func TestFoo(t *testing.T) {
	reg.MustRegister(foos)
	before := getMetricValue(foos)
	Foo()
	after := getMetricValue(foos)
	assert.Equal(t, 1, int(after-before))
}

```
</details>

## Exposition
The process of making metrics available to Prometheus is
known as exposition. Exposition to Prometheus is done over HTTP by using "/metrics" path.

## Labels
Labels are key-value pairs associated with time series, that in addition to the metric name, uniquely identify them.

An example for counter with label:

<details>
<summary> counter_with_label.go </summary>

```
package main

import (
	"log"
	"net/http"

	"github.com/gorilla/mux"
	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promhttp"
)

var (
	requests = prometheus.NewCounterVec(prometheus.CounterOpts{
		Name: "api_call_counts",
		Help: "The number of api calls",
	}, []string{"path"})
)

func main() {
	router := mux.NewRouter()
	reg := prometheus.NewRegistry()
	reg.MustRegister(requests)

	router.HandleFunc("/api/{path}", func(res http.ResponseWriter, req *http.Request) {
		vars := mux.Vars(req)
		path := vars["path"]
		requests.WithLabelValues(path).Inc()
		res.WriteHeader(http.StatusOK)
		res.Write([]byte(path))
	})
	router.HandleFunc("/", func(res http.ResponseWriter, req *http.Request) {
		requests.WithLabelValues("/").Inc()
		res.WriteHeader(http.StatusOK)
		res.Write([]byte("Hello from homepage"))

	})

	router.Handle("/metrics", promhttp.HandlerFor(reg, promhttp.HandlerOpts{}))
	server := http.Server{
		Addr:    ":8085",
		Handler: router,
	}
	log.Println("Server is running")
	log.Fatal(server.ListenAndServe())
}
```

</details>


### Metrics
```
# HELP latency_seconds Latency in seconds.
# TYPE latency_seconds summary
latency_seconds_sum{path="/foo"} 1.0
latency_seconds_count{path="/foo"} 2.0
```
Here latency_seconds is a metric family. latency_seconds_sum is a time series.

### Child
- The value returned to you by the labels method is called a child

### Aggregating
- Aggregation is a technique which allows run query on some specific time series data.


### Labels Patterns
Prometheus only supports 64-bit floating-point numbers as time series values, not any other data types such as strings. But label values are strings, and there are certain limited use cases where it is okay to (ab)use them without getting too far into logs-based monitoring.
- Enum: Enum is a string value which can be used as labels in gauge.
- Info: Info metrics are useful for annota‐
tions such as version numbers and other build information that would be useful to
query on, but it doesn’t make sense to use them as target labels

### When to use labels
- The rule of thumb is that either summing or averaging across a metric should produce a meaningful result. 
- Another thing to avoid is having a time series that is a total of the rest of the metric.


### Cardinality
- In Prometheus, Cardinality is the nunber of time series you have. 
- The rule of thumbs writer used is that the cardinality of an arbitary metrics in one application instance should be kept below ten.


## Dashboarding with Grafana
An example dashboard in grafana.

![image](static/prometheus-dashboard.png)



## Extra Resources:
- [Prometheus documentation](https://prometheus.io/docs/prometheus/latest/getting_started/)
- [Prometheus Architecture Explained](https://www.youtube.com/watch?v=h4Sl21AKiDg&t=1s)
- [Prometheus Tutorial by Edureka](https://www.youtube.com/watch?v=7gW5pSM6dlU)
