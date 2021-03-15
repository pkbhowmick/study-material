# Prometheus Up & Running

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

### The Gauge
- Gauges are a snapshot of some current state. 
- Examples of gauges include:
    - the number of items in the queue
    - memory usage of a cache
    - number of active threads
    - the last time a record was processed

- Gauges have three main methods: inc, dec and set.

