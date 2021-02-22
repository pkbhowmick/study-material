## Introducing CRD (Custom Resource Definition)

- To define a new resource type, we have to post a CustomResourceDefinition(CRD) object to the Kubernetes API server. The CustomResourceDefinition onject is the description of the custom resource type. Once the CRD is posted, user can then create custom resource by posting JSON or YAML manifest to the API server same as other Kubernetes resources.

- All kubernetes objects have an associate controller and in the same way each CRD should have an associate controller which is responsible for doing something based on the custom object.

## Creating a CustomObjectDefinition object

```
apiVersion: apiextensions.k8s.io/v1
kind: CustomResourceDefinition
metadata:
  name: crontabs.stable.example.com
spec:
  group: stable.example.com
  versions:
    - name: v1
      served: true
      storage: true
      schema:
        openAPIV3Schema:
          type: object
          properties:
            spec:
              type: object
              properties:
                cronSpec:
                  type: string
                image:
                  type: string
                replicas:
                  type: integer
  scope: Namespaced
  names:
    plural: crontabs
    singular: crontab
    kind: CronTab
    shortNames:
      - ct

```

### Code Generation for CustomResources:

#### Why Code Generation: 
CustomReources want to use:
- generated Deepcopy function: creates a method ```func (t* T) DeepCopy() *T ``` for each type T.
- typed clients: creates typed clientsets for CustomResource APIGroups
- informer: creates informer for CustomResources which offer an event based interface to react on changes of CustomResources on the server.
- lister: creates lister for customResources which offer a read-only caching layer for GET and LIST requests. Lister and informer are the basis for building controllers.

### Controlling the Generated Code - Tags
There are two kind of tags:
- Global tags above package in doc.go
- Local tags above a type that is processed

Tags in general have the shape ```// +tag-name ``` or ```// +tag-name=value```

#### Global Tags
Global tags are written into the doc.go file of a package. 
It tells deepcopy-gen to create deepcopy methods by default for every type in that package.


```
// +k8s:deepcopy-gen=package,register
// Package v1 is the v1 version of the API
// +groupName=exampole.com
package v1
```

#### Local Tags
Local tags are written either directly above an API type or in the second comment block above it.
Example:
```
// +genclient
// +genclient:noStatus
// +k8s:deepcopy-gen: interfaces=k8s.io/apimachinery/pkg/runtime.Object
```

#### Client-gen Tags


### References:
- [Extend the Kubernetes API with CustomResourceDefinitions](https://kubernetes.io/docs/tasks/extend-kubernetes/custom-resources/custom-resource-definitions/#create-a-customresourcedefinition)
- [Kubernetes in Action (Book by Marko Luska)](https://www.manning.com/books/kubernetes-in-action)
- [Blog on Code Generation for CustomResources by RedHat](https://www.openshift.com/blog/kubernetes-deep-dive-code-generation-customresources)
- [CRD API Doc](https://kubernetes.io/docs/reference/generated/kubernetes-api/v1.20/#customresourcedefinition-v1-apiextensions-k8s-io)
- [Create kubernetes custom resources definitions](https://developer.ibm.com/technologies/containers/tutorials/kubernetes-custom-resource-definitions/)
