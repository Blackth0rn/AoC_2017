type readline_interface;
type readable_stream;
type writable_stream = {.
	"write": string => Js.boolean
};

type readline_options = {.
	"input": readable_stream,
	"output": writable_stream,
	"terminal": Js.boolean
};


[@bs.module "readline"] external createInterface:
	readline_options => readline_interface = "createInterface";

[@bs.send.pipe: readline_interface] external on :
	(
		[@bs.string] [
			| `line  (string => unit)
			| `close (unit => unit)
		]
	) => readline_interface = "";

[@bs.send] external close:
	(
		readline_interface
	) => unit = "";

[@bs.send] external question:
	(
		readline_interface,
		string,
		(string) => unit
	) => unit = "";

[@bs.send] external setPrompt:
	(
		readline_interface,
		string
	) => unit = "";

[@bs.send] external prompt:
	(
		readline_interface
	) => unit = "";

[@bs.val] external process:
	{.
		"stdin": readable_stream,
		"stdout": writable_stream,
		"exit": [@bs.meth] int => unit
	} = "global.process";

let rl = createInterface(
	{
		"input": process##stdin,
		"output": process##stdout,
		"terminal": Js.false_
	}
);

let question = question(rl);
let setPrompt = setPrompt(rl);
let prompt = () => prompt(rl);
let close = () => close(rl);
