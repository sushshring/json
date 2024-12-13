# JSON_DIAGNOSTIC_POSITIONS

```cpp
#define JSON_DIAGNOSTIC_POSITIONS /* value */
```

This macro enables position diagnostics for generated JSON objects.

When enabled, two new properties: `start_pos()` and `end_pos()` are added to `nlohmann::json` objects and fields. `start_pos()` returns the start position of that JSON object/field in the original string the object was parsed from. Likewise,  `end_pos()` returns the end position of that JSON object/field in the original string the object was parsed from.

For objects and arrays, the start and end positions represent the positions of the opening and closing braces or brackets, respectively. For fields, the start and end positions represent either the opening and closing quotes for that field's value or the first and last characters in the field's numerical or predefined true/false/null values.

`start_pos()` and `end_pos()` are only defined if the JSON object was parsed using `json::parse()`. Any object built directly will return `std::string::npos` as the start and end positions.

Note that enabling this macro increases the size of every JSON value by two size_t fields and adds
slight runtime overhead.

## Default definition

The default value is `0` (position diagnostics are switched off).

```cpp
#define JSON_DIAGNOSTIC_POSITIONS 0
```

When the macro is not defined, the library will define it to its default value.

## Notes

!!! hint "CMake option"

    Diagnostic messages can also be controlled with the CMake option
    [`JSON_Diagnostic_Positions`](../../integration/cmake.md#json_diagnostic_positions) (`OFF` by default)
    which defines `JSON_DIAGNOSTIC_POSITIONS` accordingly.

## Examples

??? example "Example 1: retrieving positions"

    ```cpp
    --8<-- "examples/diagnostic_positions.cpp"
    ```
    
    Output:

    ```
    --8<-- "examples/diagnostic_positions.output"
    ```

    The output shows the start/end positions of all the objects and fields in the JSON string.
## Version history

