# JSON_DIAGNOSTIC_POSITIONS

```cpp
#define JSON_DIAGNOSTIC_POSITIONS /* value */
```

This macro enables position diagnostics for generated JSON objects.

When enabled, two new properties: `start_pos()` and `end_pos()` are added to `nlohmann::basic_json` objects and fields. `start_pos()` returns the start position of
that JSON object/field in the original string the object was parsed from. Likewise, `end_pos()` returns the end position of that JSON object/field in the
original string the object was parsed from.

For objects and arrays, the start position represents the position of the opening brace or bracket. The end position is the character after the closing
brace or bracket. For fields, the start position represents the opening quote or first character in field's numerical or predefined (true/false/null) value,
the end position represents the character after the closing quote or the character after the last character in the field's numerical or predefined value.

Given the above, `end_pos() - start_pos()` for an object or field provides the length of the string representation for that object or field, including the
opening or closing braces, brackets, or quotes.

`start_pos()` and `end_pos()` are only set if the JSON object was parsed using `parse()`. For all other cases, `std::string::npos` will be returned.

Note that enabling this macro increases the size of every JSON value by two `std::size_t` fields and adds
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

