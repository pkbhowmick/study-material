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

## Kubernetes Architecture

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



## Minikube

## Kubectl

## Master

## Node

## Pod

- The smallest unit to interact & configure.
## Service

## Add Label to service

## Running multiple instance (Scaling)




