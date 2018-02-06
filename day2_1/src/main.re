open Readline;

setPrompt("Input:");
prompt();

rl
|> on(`line((line) => {
	switch(line) {
	| "exit" => close()
	| _ => Js.log(line)
	};
	prompt();
	();
}))
|> on(`close(() => {
	Js.log("Bye");
	process##exit(0);
	();
}));

