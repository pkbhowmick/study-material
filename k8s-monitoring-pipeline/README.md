# Kubernetes Monitoring Pipeline

Monitoring is spilt into two pipelines:

- Core metrics pipeline

- Monitoring pipeline

## Core metrics Pipeline

The core metrics pipeline collects a set of core system metrics. There are two sources for these metrics.

- Kubelet: providing per node/pod/container usage information

- A resource estimator that runs as a DaemonSet and turns raw usage values scraped from Kubelet into resource estimates

These sources are scraped by a component we call metric-server. Metrics server stores only latest values and exposes the master metrics API.

A core metrics pipeline consists of:

- Kubelet
- A resource estimator
- Metrics-server
- API server

Usage: These metrics are used by core system components, such as scheduling logic i.e. horizontal pod autoscaling based on system metrics.


### Kubernetes Metrics Server
- Metrics server is a scalable, efficient source of container resource metrics for Kubernetes built-in auto scaling pipeline.

- Metrics server collects resource metrics from kubelets and expose them in kubernetes api server through metrics api for use by horizontal and vertical pod auto scaler.

Usages: 
- CPU/memory based horizontal auto scaling (Horizontal pod auto scaler)
- Automatically adjusting/suggesting resources needed by containers (Vertical pod auto scaler)

N.B. Metrics Server is not for non-autoscaling purposes. It shouldn't be used to forward metrics to monitoring solutions or as a source of monitoring solutions metrics. 




## Monitoring Pipeline
A monitoring pipeline used for collecting various metrics from the system and expose them to the end users. Data collected from monitoring pipeline may content of the following group of metrics:
- core system metrics
- non core system metrics
- service metrics from user applications
- service metrics from Kubernetes infrastructure containers

## Resources
- [Kubernetes Monitoring Architecture](https://github.com/kubernetes/community/blob/master/contributors/design-proposals/instrumentation/monitoring_architecture.md)

- [Kubernetes Metrics Server](https://github.com/kubernetes-sigs/metrics-server)

- [Kubernetes Metrics Options](https://blog.containership.io/kubernetes-metrics-collection-options/)

