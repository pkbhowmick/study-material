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
