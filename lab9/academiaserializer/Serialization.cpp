//
// Created by owsikami on 09.05.18.
//

#include "Serialization.h"

void academia::Room::Serialize(academia::Serializer *c) const {
    c->Header("room");
    c->IntegerField("id", id_);
    c->StringField("name", name_);
    c->StringField("type", EnumToString(type_));
    c->Footer("room");
}

std::string academia::Room::EnumToString(academia::Room::Type enumerator) const {
    switch (enumerator)
    {
        case academia::Room::Type::COMPUTER_LAB:   return "COMPUTER_LAB";
        case academia::Room::Type::CLASSROOM:   return "CLASSROOM";
        case academia::Room::Type::LECTURE_HALL: return "LECTURE_HALL";

    }

}

void academia::Building::Serialize(academia::Serializer *c) const{
    c->Header("building");
    c->IntegerField("id", id_);
    c->StringField("name", name_);
    c->ArrayField("rooms", rooms_);
    c->Footer("building");

}


void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": "+std::to_string(value);


}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": "+std::to_string(value);
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": \""+value +"\"";
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": \""+std::to_string(value) +"\""; //!!!!!!!!!!!!!!!!!!
}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": ";
    out_<<"[";
    bool is_first_serializable = true;
    for(auto i:value){
        if(is_first_serializable){
            is_first_serializable= false;
        } else {
            out_<<", ";
        }
        
        is_first_=true;
        i.get().Serialize(this);
    }


    out_<<"]";

}

void academia::JsonSerializer::Header(const std::string &object_name) {
    out_<<"{";

}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    //usuń 2 ostatnie znaki?
    out_<<"}";

}
