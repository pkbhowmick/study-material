## User Account vs Service Account
- User accounts are for humans and service accounts are for processes that run on pods.
- User accounts are intended to be global. Service accounts are namespaced.
- Ref: [Managing Service Account k8s](https://kubernetes.io/docs/reference/access-authn-authz/service-accounts-admin/)

## RBAC
The RBAC API declares four kinds of Kubernetes object: Role, ClusterRole, RoleBinding and ClusterRoleBinding

### Role and ClusterRole
- An RBAC Role or ClusterRole contains rules that represent a set of permissions.
- A role always sets permissions within a particular namespace where ClusterRole is a non-namespaced resource.
- ClusterRoles have several uses:
  - define permissions on namespaced resources and be granted within individual namespace
  - define permissions on namespaces resources and be granted across all namespaces
  - define permissions on cluster-scoped resources
    
But to define a role within a namespace Role is preferred while ClusterRole should be used for cluster-wide role.

### RoleBinding and ClusterRoleBinding
- A RoleBinding grants the permissions defined in a role to a user or a set of users. A RoleBinding grants permissions within a specific namespace whereas a ClusterRoleBinding grants that access cluster-wide.
- A RoleBinding may reference any Role in the same namespace and also can reference a ClusterRole to the namespace of the RoleBinding.

### Aggregated ClusterRoles
Aggregation rule can be used to aggregate rules into existing ClusterRole. The aggregationRules defines a label selector that the controller uses to match other ClusterRole objects that should be combined into the rules field of this one.

#### RBAC tutorials
- [Role Based Access Control(RBAC) with Kubernetes](https://www.youtube.com/watch?v=BLktpM--0jA)
- [Understand Role Based Access Control in Kubernetes](https://www.youtube.com/watch?v=G3R24JSlGjY)