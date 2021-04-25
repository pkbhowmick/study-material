package main

import (
	"context"
	pb "github.com/pkbhowmick/study-material/grpc/proto"
	"google.golang.org/grpc"
	"log"
	"net"
)

const port = ":50051"

type server struct {
	pb.UnimplementedGreeterServer
}

func (s *server) SayHello(ctx context.Context, in *pb.HelloRequest) (*pb.HelloReply, error) {
	log.Printf("Received %v\n",in.GetName())
	return &pb.HelloReply{Message: "Hello " + in.GetName()}, nil
}

func main()  {
	lis, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("failed to listen: %v\n",err)
	}
	s := grpc.NewServer()
	pb.RegisterGreeterServer(s, &server{})
	log.Println("server is listening")
	if err:= s.Serve(lis); err!=nil {
		log.Fatalf("failed to serve: %v\n",err)
	}
}
