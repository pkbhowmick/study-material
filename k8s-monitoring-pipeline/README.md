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


## Resources
- [Kubernetes Monitoring Architecture](https://github.com/kubernetes/community/blob/master/contributors/design-proposals/instrumentation/monitoring_architecture.md)
