package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readline(r *bufio.Reader) string {
	var (
		isPrefix bool  = true
		err      error = nil
		line, ln []byte
	)
	for isPrefix && err == nil {
		line, isPrefix, err = r.ReadLine()
		ln = append(ln, line...)
	}
	if err != nil {
		fmt.Println("could not read line.")
		fmt.Println(err)
		os.Exit(1)
	}
	return string(ln)
}

func to_uinteger(numstr string) uint64 {
	var numbr uint64
	var err error
	numbr, err = strconv.ParseUint(numstr, 10, 64)
	if err != nil {
		fmt.Println("could not convert to integer")
		fmt.Println(err)
		os.Exit(1)
	}
	return numbr
}

func to_double(numstr string) float64 {
	var rv float64
	var err error
	rv, err = strconv.ParseFloat(numstr, 64)
	if err != nil {
		fmt.Println("could not convert to float64")
		fmt.Println(err)
		os.Exit(1)
	}
	return rv
}

func binary_to_uinteger(numstr string) uint64 {
	var numbr uint64
	var err error
	numbr, err = strconv.ParseUint(numstr, 2, 64)
	if err != nil {
		fmt.Println("could not convert binary to integer")
		fmt.Println(err)
		os.Exit(1)
	}
	return numbr
}

func count_bits(num uint64) uint64 {
	var rv uint64
	rv = 0
	for num != 0 {
		if (num & 1) == 1 {
			rv++
		}
		num = num >> 1
	}
	return rv
}

func chaos(inputfile string, outputfile string) {
	var fh_out *os.File
	var fh_original *os.File
	var fh_in *bufio.Reader
	var err error
	var in_line string
	var test_cases uint64
	var test_number uint64
	var result string
	var nandl []string
	var num_devices uint64
	// var num_switches uint64
	var outletsints []uint64
	var devicesints []uint64
	var outletsstr []string
	var i uint64
	var devicesstr []string
	var seen_map map[uint64]bool
	var stuff_to_update []uint64
	var stuff_to_remove []uint64
	var exists bool
	var deviceval uint64
	var xorval uint64
	var j uint64
	var y uint64
	// var z bool
	// var lpidx int
	var mindefined bool
	var bits uint64
	var minval uint64

	fh_out, err = os.Create(outputfile)
	if err != nil {
		fmt.Printf("Could not open outputfile: %s", outputfile)
		return
	}
	defer fh_out.Close()
	fh_original, err = os.Open(inputfile)
	if err != nil {
		fmt.Printf("Not found: %s", inputfile)
		return
	}
	defer fh_original.Close()
	fh_in = bufio.NewReader(fh_original)
	in_line = readline(fh_in)
	test_cases = to_uinteger(in_line)
	for test_number = 1; test_number <= test_cases; test_number++ {
		in_line = readline(fh_in)
		nandl = strings.Split(in_line, " ")
		num_devices = to_uinteger(nandl[0])
		// num_switches = to_uinteger(nandl[1])
		outletsints = make([]uint64, num_devices)
		devicesints = make([]uint64, num_devices)

		in_line = readline(fh_in)
		outletsstr = strings.Split(in_line, " ")
		for i = 0; i < num_devices; i++ {
			outletsints[i] = binary_to_uinteger(outletsstr[i])
		}
		in_line = readline(fh_in)
		devicesstr = strings.Split(in_line, " ")
		for i = 0; i < num_devices; i++ {
			devicesints[i] = binary_to_uinteger(devicesstr[i])
		}
		// algorithm: make map of first device, eliminate from map on subsequent deviceses
		seen_map = make(map[uint64]bool)
		deviceval = devicesints[0]
		for i = 0; i < num_devices; i++ {
			xorval = deviceval ^ outletsints[i]
			seen_map[xorval] = false
		}
		for j = 1; j < num_devices; j++ {
			stuff_to_update = make([]uint64, 0)
			for y, _ = range seen_map {
				stuff_to_update = append(stuff_to_update, y)
			}
			for _, y = range stuff_to_update {
				seen_map[y] = false
			}
			deviceval = devicesints[j]
			for i = 0; i < num_devices; i++ {
				xorval = deviceval ^ outletsints[i]
				_, exists = seen_map[xorval]
				if exists {
					seen_map[xorval] = true
				}
			}
			stuff_to_remove = make([]uint64, 0)
			for y, _ = range seen_map {
				if seen_map[y] == false {
					stuff_to_remove = append(stuff_to_remove, y)
				}
			}
			for _, y = range stuff_to_remove {
				delete(seen_map, y)
			}

		}
		// find the minimum value in seen_map
		mindefined = false
		for y, _ = range seen_map {
			bits = count_bits(y)
			if mindefined {
				if bits < minval {
					minval = bits
				}
			} else {
				minval = bits
				mindefined = true
			}
		}
		if mindefined {
			result = strconv.FormatUint(minval, 10)

		} else {
			result = "NOT POSSIBLE"
		}
		_, err = fmt.Fprintf(fh_out, "Case #%d: %s\n", test_number, result)
		if err != nil {
			fmt.Println("Error on output")
		}
	}
}

func main() {
	var file_base string
	var inputfile string
	var outputfile string

	file_base = "A-small-attempt1"
	inputfile = file_base + ".in"
	outputfile = file_base + ".out"
	chaos(inputfile, outputfile)
}
