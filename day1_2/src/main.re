open Readline;

let arrayOfInts = [||];
let mapToArray = (char: char) => {
	let charString = String.make(1,char);
	let intFromChar = int_of_string(charString);
	let _ = Js.Array.push(intFromChar, arrayOfInts);
	();
};

let handleInput = (input) => {
	String.iter(mapToArray, input);
	let halfArrayLength = Array.length(arrayOfInts) / 2;
	let firstHalf = Array.sub(arrayOfInts, 0, halfArrayLength);
	let secondHalf = Array.sub(arrayOfInts, halfArrayLength, halfArrayLength );

	/* If the firstHalf item at this index matches the secondHalf item
	at the same index then we want to keep it. Double the value as
	the reverse match is also true (secondHalf[x] == firstHalf[x]) */
	let matching = Array.mapi((idx, item) => {
		(item == secondHalf[idx]) ? item * 2 : 0
	}, firstHalf);

	Js.log(Array.fold_left((carry, value) => {
		carry + value
	}, 0, matching));
};

question("What's the input?\n", handleInput);
