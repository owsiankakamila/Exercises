//
// Created by owsikami on 09.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <ostream>
#include <vector>

namespace academia {

    class Serializer; //nie mozesz uzyc jako wartosci i nie mozesz dziedziczyc

    class Serializable{
        virtual void Serialize (Serializer * c)=0;
    };

    class Serializer{
    public:
        Serializer(std::ostream *out) :out_(*out) {}
        virtual  void IntegerField(const std::string &field_name, int value) =0;

        virtual void DoubleField(const std::string &field_name, double value) =0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;

    private:
        std::ostream & out_;
    };

    class Room: public Serializable{
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(int id, std::string name, Type type ): id_(id), name_(name), type_(type){}
        void Serialize(Serializer *c) override;
        std::string EnumToString(Type enumerator);




    private:
        int id_;
        std::string name_;
        Type type_;

    };




}


#endif //JIMP_EXERCISES_SERIALIZATION_H
