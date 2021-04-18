package main

import (
	"context"
	pb "github.com/pkbhowmick/study-material/grpc/proto"
	"google.golang.org/grpc"
	"log"
	"os"
	"time"
)

const (
	address = "localhost:50051"
	defaultName = "pkbhowmick"
)


func main()  {
	conn, err := grpc.Dial(address, grpc.WithInsecure(), grpc.WithBlock())
	if err!= nil {
		log.Fatalf("didn't connect: %v\n",err)
	}
	defer conn.Close()

	client := pb.NewGreeterClient(conn)

	name := defaultName
	if len(os.Args) > 1 {
		name = os.Args[1]
	}
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	res, err := client.SayHello(ctx, &pb.HelloRequest{Name: name})
	if err!= nil {
		log.Fatalf("couldn't greet: %v\n",err)
	}
	log.Printf("Greeting : %s\n",res.GetMessage())
}