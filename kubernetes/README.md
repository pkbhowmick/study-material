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




