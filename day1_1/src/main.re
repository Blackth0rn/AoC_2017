open Node.Fs;
open String;
open List;

let rec string_to_int_list = (string) => {
	switch string {
	| "" => []
	| "\n" => []
	| ns => [int_of_char(ns.[0]) - 48, ...string_to_int_list(String.sub(ns, 1, String.length(ns)-1))]
	}
};

let print_int = (int) => {
	Js.log(string_of_int(int));
};

let sum_consecutive = (lst) => {
	let rec adder = (inner_lst) => {
		switch inner_lst {
		| [] => 0
		| [num] => num == List.hd(lst) ? num : 0
		| [num, ...rest] => num == List.hd(rest) ? num + adder(rest) : 0 + adder(rest)
		}
	};
	adder(lst)
};

let filename = "input.txt";

let contents = readFileSync(filename, `utf8);

Js.log("Input: " ++ contents);

Js.log("Input length: " ++ string_of_int(String.length(contents)));

let list_of_ints = string_to_int_list(contents);

List.map( print_int, list_of_ints);

Js.log("Output: " ++ string_of_int(sum_consecutive(list_of_ints)));
