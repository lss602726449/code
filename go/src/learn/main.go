package main

import (
	"fmt"
	"learn/test"
)

func add(a int, b int) (int, string) {
	n := a + b
	return n, fmt.Sprintf("%d", n)
}

func main() {
	fmt.Println("Hello, World!")
	n, s := add(1, 2)
	fmt.Println(n)
	fmt.Println(s)
	test.Test()
}
