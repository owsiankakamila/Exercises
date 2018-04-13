//
// Created by kamila on 23.03.18.
//

#include <map>
#include <experimental/optional>
#include "SimpleJson.h"

nets::JsonValue::JsonValue(int int_val) {

}

nets::JsonValue::JsonValue(double double_val) {

}

nets::JsonValue::JsonValue(std::string string_val) {

}

nets::JsonValue::JsonValue(bool bool_val) {

}

nets::JsonValue::JsonValue(nets::JsonValue *array_val) {

}

nets::JsonValue::JsonValue(std::map<std::string, nets::JsonValue> object_val) {

}

std::experimental::optional<nets::JsonValue> nets::JsonValue::ValueByName(const std::string &name) const {
    return std::experimental::optional<nets::JsonValue>();
}

std::string nets::JsonValue::ToString() const {
    return std::__cxx11::string();
}
