//
// Created by owsikami on 09.05.18.
//

#include "Serialization.h"

void academia::Room::Serialize(academia::Serializer *c) {
    c->Header("Room");
    c->IntegerField("id", id_);
    c->StringField("name", name_);
    c->StringField("type", EnumToString(type_));

    c->Footer("Room");


}

std::string academia::Room::EnumToString(academia::Room::Type enumerator) {
    switch (enumerator)
    {
        case academia::Room::Type::COMPUTER_LAB:   return "COMPUTER_LAB";
        case academia::Room::Type::CLASSROOM:   return "CLASSROOM";
        case academia::Room::Type::LECTURE_HALL: return "LECTURE_HALL";

    }

}
