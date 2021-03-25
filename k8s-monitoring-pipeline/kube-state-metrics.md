# kube-state-metrics overview

## kube-state-metrics 
- kube-state-metrics is a simple server that listens to the Kubernetes API server and gererates metrics about the state of the objects.

- It is focused on the health of the various objects inside, such as deployments, nodes and pods.

- kube-state-metrics is about generating metrics from kubernetes API objects without modification.

- The metrics are exposed on the HTTP endpoint ```/metrics``` on the listening port (default 8080). They are served as plaintext. They are designed to be consumed either by Prometheus itself or by a scaraper that is compatible with scraping a Prometheus client endpoint.


## Components

- Builder: Builder helps to build store. It follows builder design pattern.

Builder design pattern: [Builder Design Pattern](https://www.geeksforgeeks.org/builder-design-pattern/)

