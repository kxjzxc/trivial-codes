local foo = import "./foo.jsonnet";
local b = std.extVar("b");

{
    "a":1,
    "b":0,
    "c":0,
    "d":0
}+(

    if b == "1" then foo['c'] else if b == "2" then foo['d'] else {}
)