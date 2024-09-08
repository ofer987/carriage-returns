package main

import (
	"fmt"
	"os"
	"path"
)

const root = ".."
const cApplication = "create_markdown_file_in_c"
const fileName = "text2.md"

func main() {
	filePath := path.Join(root, cApplication, fileName)

	data, err := os.ReadFile(filePath)
	check(err)
	for index, byt := range data {
		fmt.Printf("For Index %d: Character is:\t%c.\tCode is: %d.\n", index, byt, byt)
	}
}

func check(err error) {
	if err != nil {
		panic(err)
	}
}
