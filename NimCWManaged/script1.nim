proc HelloFromNim(a, b: int): int {.exportc, dynlib.} =
    echo("Hello from Nim!");
