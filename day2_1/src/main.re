open Readline;

setPrompt("Input:");
prompt();

let rec listChar = (line) => {
	Js.log(line);
	switch(line) {
		| "" => []
		| part => {
			switch(String.index(part, '\t')) {
				| value => [int_of_string(String.sub(part, 0, value)), ...listChar(String.sub(part, value + 1, String.length(part) - value - 1))]
				| exception Not_found => [int_of_string(String.sub(part, 0, String.length(part)))]
			};
		}
	}
};

let lines = [||];

let handleLine = (line) => {
	let intList = listChar(line);
	Js.log(intList);
	let _ = Js.Array.push(intList, lines);
};

let calculateChecksumLine = (carry, line) => {
	let max = List.fold_left((curMax, num) => {
		(curMax > num) ? curMax : num;
	}, 0, line);
	let min = List.fold_left((curMin, num) => {
		(curMin < num) ? curMin : num;
	}, max_int, line);
	carry + (max - min);
};
let calculateChecksum = (lines) => {
	let result = Array.fold_left(calculateChecksumLine, 0, lines);
	Js.log(result);
};

rl |> on(`line((line) => {
	switch(line) {
	| "exit" => close()
	| "calc" => calculateChecksum(lines)
	| x => handleLine(x)
	};
	prompt();
	();
}))
|> on(`close(() => {
	Js.log("Bye");
	process##exit(0);
	();
}));
