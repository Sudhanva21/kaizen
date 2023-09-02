﻿// MIT License
// 
// Copyright (c) 2023 Leo Heinsaar
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "test_kaizen.h"

int main()
{
	zen::filestring filestr("../LICENSE.txt");
	zen::string	  first = filestr.getline(1);
	const zen::string v = first.extract_pattern(R"((\d+\.\d+\.\d+))"); // version
	
	zen::print(zen::color::blue("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"));
	zen::print(zen::color::blue("|||||||||||||||||||||||||||| KAIZEN"), v, zen::color::blue("||||||||||||||||||||||||||||\n"));
	zen::print(zen::color::blue("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"));
	zen::print(zen::color::blue("RUNNING TESTS...\n"));

	// Test data structures
	sanitest_filestring();
	sanitest_string();
	sanitest_vector();
	sanitest_array();
	sanitest_deque();
	sanitest_list();

	// Test utilities
	sanitest_utils();
}
