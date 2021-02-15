package main

import (
	"fmt"
	"os"
	"text/template"
)

type Inventory struct {
	Material string
	Count int
}

type Coupon struct {
	Name string
	Amount int
	Code string
}

func main()  {
	// ****************************** Simple example ******************************
	sw := Inventory{
		Material: "wool",
		Count:    17,
	}
	tmpl, err := template.New("test").Parse("{{.Count}} items are made of {{.Material}}\n")
	if err != nil{
		panic(err)
	}
	err = tmpl.Execute(os.Stdout, sw)
	if err != nil {
		panic(err)
	}

	// ***************************** Simple example with file parsing *******************
	htmlPage , err := template.ParseFiles("index.gohtml")
	if err != nil {
		panic(err)
	}
	coupon := Coupon{
		Name:   "Rick",
		Amount: 100,
		Code: "PANDA100",
	}
	err = htmlPage.Execute(os.Stdout, coupon)
	if err != nil {
		panic(err)
	}

	// ********************************** Example with Array ***************************
	user := []string{"Mike", "Rick", "Morty"}
	userList, err := template.ParseFiles("user.gohtml")
	if err != nil {
		panic(err)
	}
	err = userList.Execute(os.Stdout, user)
	if err != nil {
		panic(err)
	}
	// ************************************* Example with map ***************************
	products := map[string]int{
		"Processor" : 17000,
		"Mainboard" : 12000,
		"Ram" : 4500,
	}
	productList , err := template.ParseFiles("product.gohtml")
	if err != nil {
		panic(err)
	}
	err = productList.Execute(os.Stdout, products)
	if err != nil {
		panic(err)
	}

	// ********************** Example of if else and slice of struct *************************
	c1 := Coupon{
		Name: "Rick",
		Amount: 50,
		Code: "PANDA50",
	}
	c2 := Coupon{
		Name: "Morty",
		Amount: 100,
		Code: "PANDA100",
	}
	coupons := []Coupon{c1,c2}
	couponList, err := template.ParseFiles("coupon.gohtml")
	if couponList == nil {
		fmt.Println("List is empty!")
	} else {
		err = couponList.Execute(os.Stdout,coupons)
		if err != nil {
			panic(err)
		}
	}
}

