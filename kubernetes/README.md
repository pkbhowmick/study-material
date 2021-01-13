# Kubernetes study materials


## Orchestration tools offer
- High Availability or no downtime
- Scalability or high performance
- Disaster recovery - backup and restore

## Kubernetes Basic Interactive tutorial

Resource: https://kubernetes.io/docs/tutorials/kubernetes-basics/

### Step #01 : Create a kubernetes cluster

- Install minikube from [here](https://minikube.sigs.k8s.io/docs/start/)
- ```$ minikube version``` [to check minikube is installed properly]
- ```$ minikube start``` [to run kubernetes cluster locally. Minikube started a VM and now a kubernetes cluster is running in that VM]
- Install kubectl from [here](https://kubernetes.io/docs/tasks/tools/install-kubectl/). kubectl is kubernetes command line interface which uses the kubernetes API to interact with the cluster.
- ```$ kubectl version``` [to check kubectl is installed properly]
- ```$ kubectl cluster-info``` [to view the cluster details]
- ```$ kubectl get nodes``` [to view the nodes in the cluster]

### Step #02 : Deploy an app

- ```$ kubectl create deployment <deployment_name> --image=<image_location>``` Note: Include the full repository url for images outside Docker hub.
- ```$ kubectl create deployment go-api-server --image=pkbhowmick/go-rest-api:latest``` [to deploy go-rest-api image in kubernetes]
- ```$ kubectl get deployments``` [to see the list of all deployments]
- ```$ kubectl proxy``` Note: Pods running inside kubernetes running on a private, isolated network and by default they are visible within the same kubernetes cluster. kubectl command can create a proxy that will provide API endpoint to communicate with our application.

### Step #03 : Explore the app

- ```$ kubectl get pods``` [to see the existing pods]
- ```$ kubectl describe pods``` [to view what containers are inside that Pod and what images are used to build those containers]
- ```$ kubectl logs $POD_NAME``` [to view the logs of the pod]
- ```$ kubectl exec $POD_NAME env``` [to view the list of environment variables of the pod]
- ```$ kubectl exec -ti $POD_NAME sh``` [to start a shell session inside the pod]

### Step #04 : Expose the app publicly

- ```$ kubectl get services``` [to see the list of services] Note: Although each Pod has a unique IP address, those IPs are not exposed outside the cluster without a Service. Services allow your applications to receive traffic.
- ```$ kubectl expose deployment/go-api-server --type="NodePort" --port=8080``` Note: We have a Service called kubernetes that is created by default when minikube starts the cluster. To create a new service and expose it to external traffic we’ll use the expose command with NodePort as parameter
- ```$ kubectl describe services/go-rest-api``` [To find out what port was opened externally (by the NodePort option)]
- ```$ export NODE_PORT=$(kubectl get services/go-api-server -o go-template='{{(index .spec.ports 0).nodePort}}')``` [Create an environment variable called NODE_PORT that has the value of the Node port assigned]
- ```$ echo NODE_PORT```
- ```$ curl --user admin:demo $(minikube ip):$NODE_PORT/api/users``` Note: Now APIs are accessible publicly by nodeport and minikube ip

### Step #05 : Scale up the app

- ```$ kubectl get rs``` [To see the ReplicaSet created by the Deployment]
- ```$ kubectl scale deployments/go-api-server --replicas=4``` [To scale up we'll use the kubectl scale command, followed by the deployment type, name and desired number of instances]

## Kubernetes Basic Architecture

### Master node

- API server
- Scheduler
- Controller manager
- ETCD
  
### Worker node

- kubelet
- kube-proxy
- pod
- container runtime


## Kubernetes Object Management 

- Imperative commands
- Imperative object configuration
- Declarative object configuration

## Namespaces

### Kubernetes starts with four initial namespaces.
- default (default namespace)
- kube-system (used by the kubernetes system)
- kube-public (publicly available namespaces)
- kube-node-lease (heartbeat of the cluster)

### Use cases when to use namespaces:

- structure components
- avoid conflicts between teams
- share services between different environments
- access and resource limit on namespace level

## Labels and selectors

- Labels are key/value pairs that area attached to objects, such as pods.
- Via a label selector, the client/user can identify a set of objects. The label selector is the core grouping primitive in Kubernetes.

## Field Selectors

- Field selectors let you select Kubernetes resources based on the value of one or more resource fields. like:

```$ kubectl get pods --field-selector status.phase=Running```
  
## Cluster Architecture
### Node
- A node may be a virtual or physical machine, depending on the cluster. Each node contains the services necessary to run Pods, managed by the control plane.
- The components on a node include the kubelet, a container runtime, and the kube-proxy.

### Node controller
The node controller is a Kubernetes control plane component that manages various aspects of nodes.
The node controller has multiple roles:
- Assigning a CIDR block to the node
- Keeping the node controller's internal list of nodes up to date.
- Monitoring the node's health

## Control Plane - Node Communication
### Node to Control Plane(API Server)

- Kubernetes has a "hub-and-spoke" API pattern. All API usage from nodes terminate at the apiserver.
- The apiserver is configured to listen for remote connections on a secure HTTPS port (typically 443) with one or more forms of client authentication enabled. 

### Control Plane to Node

- apiserver to kubelet: The connection from apiserver to kubelet are used for:
    - Fetching logs for pods 
    - Attching to running pods
    - Providing the kubelet's port-forwarding functionality
- apiserver to nodes, pods, and services: The connections from the apiserver to a node, pod, or service default to plain HTTP connections and are therefore neither authenticated nor encrypted. These connections are not currently safe to run over untrusted and/or public networks.

### SSH tunnels

- Kubernetes supports SSH tunnels to protect the control plane to nodes communication paths.
- This tunnel ensures that the traffic is not exposed outside the network in which the nodes are running.
- SSH tunnels are currently deprecated, and the konnectivity service is a replacement for this communication channel

### Konnectivity service

- As a replacement to the SSH tunnels, the Konnectivity service provides TCP level proxy for the control plane to cluster communication.
- The Konnectivity service consists of two parts: the Konnectivity server and the Konnectivity agents, running in the control plane network and the nodes network respectively. 

## Controllers
In Kubernetes, controllers are control loops that watch the state of your cluster, then make or request changes where needed. Each controller tries to move the current cluster state closer to the desired state.

- Control via API server: The Job controller is an example of a Kubernetes built-in controller. Built-in controllers manage state by interacting with the cluster API server.
- Direct control: By contrast with Job, some controllers need to make changes to things outside of your cluster.

## Cloud Controller Manager
The cloud-controller-manager is a Kubernetes control plane component that embeds cloud-specific control logic. The cloud controller manager lets you link your cluster into your cloud provider's API, and separates out the components that interact with that cloud platform from components that just interact with your cluster.

### Cloud controller manager functions

- Node controller: The node controller is responsible for creating Node objects when new servers are created in your cloud infrastructure.
- Route controller: The route controller is responsible for configuring routes in the cloud appropriately so that containers on different nodes in your Kubernetes cluster can communicate with each other.
- Service controller: Services integrate with cloud infrastructure components such as managed load balancers, IP addresses, network packet filtering, and target health checking.

## Containers
- Each container that we run is repeatable means that you get the same behavior wherever we run it. 
- A container image is a ready-to-run software package, containing everything needed to run an application.
- The container runtime is the software that is responsible for running containers. Kubernetes supports several container runtimes: Docker, containerd, CRI-O or any implementation of the Kubernetes CRI (Container Runtime Interface).

### Images

- A container image represents binary data that encapsulate an application and all its software dependencies.
- Updating images: The default pull policy is IfNotPresent which causes the Kubelet to skip pulling an image if it already exist. We can use imagePullPolicy of the container to *Always* to always force a pull.
- Configure nodes to authenticate to a private registry: We can copy our local .docker/config.json(which already has auth key for docker hub) file to every node like root@"$n":/var/lib/kubelet/config.json. After that kubelet will use that config file for pulling image from a private registry.
- Usecases:
   - Cluster running only open-source images. No need to hide images.
   - Cluster running some proprietary images which should be hidden to those outside the company, but visible to all cluster users.
   - Cluster with proprietary images, a few of which require stricter access control.
   - A multi-tenant cluster where each tenant needs own private registry.
  
### Container Environment
The Kubernetes Container environment provides several important resources to Containers:

- A filesystem, which is a combination of an image and one or more volumes.
- Information about the Container itself.
- Information about other objects in the cluster.

### Runtime Class
RuntimeClass is a feature for selecting the container runtime configuration. The container runtime configuration is used to run a Pod's containers.
RuntimeClass can be setup in two ways:
- Configure the CRI implementation on nodes
- Create the corresponding RuntimeClass resources

### Container Lifecycle Hooks
The hooks enable Containers to be aware of events in their management lifecycle and run code implemented in a handler when the corresponding lifecycle hook is executed.

There are two hooks that are exposed to Containers:
- PostStart: This hook is executed immediately after a container is created.
- PreStop: This hook is called immediately before a container is terminated due to an API request or management event such as liveness probe failure, preemption, resource contention and others.

Hook handler implementations: Containers can access a hook by implementing and registering a handler for that hook. There are two types of hook handlers that can be implemented for Containers:
- Exec: Execute a specific command
- HTTP: Execute an HTTP request 

Hook handler execution: 
- When a Container lifecycle management hook is called, the Kubernetes management system execute the handler according to the hook action, exec and tcpSocket are executed in the container, and httpGet is executed by the kubelet process.
- Hook handler calls are synchronous.
- Hook delivery is guaranteed.

## Workloads
A workload is an application running on Kubernetes. Kubernetes provides several built-in workload resources:
- Deployment and ReplicaSet
- StatefulSet
- DaemonSet
- Job and CronJob
### Pods
Pods are the smallest deployable units of computing that you can create and manage in Kubernetes.

A Pod (as in a pod of whales or pea pod) is a group of one or more containers, with shared storage/network resources, and a specification for how to run the containers.

Pods in a Kubernetes cluster are used in two main ways:
- Pods that run a single container
- Pods that run multiple containers that need to work together

Here are some examples of workload resources that manage one or more pods:
- Deployment
- StatefulSet
- DaemonSet

Pod templates: The sample below is a manifest for a simple Job with a template that starts one container. The container in that Pod prints a message then pauses.
```
apiVersion: batch/v1
kind: Job
metadata:
  name: hello
spec:
  template:
    # This is the pod template
    spec:
      containers:
      - name: hello
        image: busybox
        command: ['sh', '-c', 'echo "Hello, Kubernetes!" && sleep 3600']
      restartPolicy: OnFailure
    # The pod template ends here
```

### Pod Lifecycle
Pods follow a defined lifecycle, starting in the Pending phase, moving through Running if at least one of its primary containers starts OK, and then through either the Succeeded or Failed phases depending on whether any container in the Pod terminated in failure.

### Init Containers
During Pod startup, the kubelet delays running init containers until the networking and storage are ready. Then the kubelet runs the Pod's init containers in the order they appear in the Pod's spec.

Each init container must exit successfully before the next container starts. If a container fails to start due to the runtime or exits with failure, it is retried according to the Pod restartPolicy.

### Pod Topology Spread Constraints
Topology spread constraints can be used to control how Pods are spread across the cluster among failure-domains such as regions, zones, nodes, and other user-defined topology domains. This can help to achieve high availability as well as efficient resource utilization.

### Ephemeral Containers
Ephemeral Conatainers is a special type of container that runs temporarily in an existing Pod to accomplish user-initiated actions such as troubleshooting.








