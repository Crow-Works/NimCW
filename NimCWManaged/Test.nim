
proc HelloFromNimWithParams( arg2: cstring) {.exportc, dynlib, cdecl.} =
  echo "Second parameter (string): ", arg2

proc HelloFromNimNoParams() {.exportc, dynlib.} =
  echo "Hello from Nim with no parameters"

