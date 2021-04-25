# grpc

## Important commands

- Generating Client and Server code:
  ```
  protoc --go_out=. --go_opt=paths=source_relative \
  --go-grpc_out=. --go-grpc_opt=paths=source_relative \
  <file_path>
  ```


## References:
- [grpc quick start guide for go](https://grpc.io/docs/languages/go/quickstart/)
- [grpc basic tutorial for go](https://grpc.io/docs/languages/go/basics/)