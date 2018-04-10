//
// Created by kamila on 23.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>


namespace nets {
    class JsonValue {
    public:
        JsonValue (int int_val);
        JsonValue (double double_val);
        JsonValue (std::string string_val);
        JsonValue (bool bool_val);
        JsonValue (JsonValue array_val []);
        JsonValue ( std::map<std::string, JsonValue> object_val);


        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;


    private:
        int int_val_;
        double double_val_;
        std::string string_val_;
        bool bool_val_;
        JsonValue array_val_ [];
        std::map<std::string, JsonValue> object_val_;

    };
}




#endif //JIMP_EXERCISES_SIMPLEJSON_H
