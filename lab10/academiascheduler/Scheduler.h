//
// Created by kamila on 16.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <set>
#include <map>
namespace academia{

    class SchedulingItem{ // item from the schedule
    public:
        SchedulingItem(int course_id,int teacher_id, int room_id, int time_slot, int year): course_id_(course_id),
                                                                                            teacher_id_(teacher_id),
                                                                                            room_id_(room_id),
                                                                                            time_slot_(time_slot),
                                                                                            year_(year){}

        //checking methods
        int CourseId() const{ return course_id_;}
        int TeacherId() const{ return teacher_id_;}
        int RoomId() const{ return room_id_;}
        int TimeSlot() const{ return time_slot_;}
        int Year() const { return year_;}


    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;

    };

    class Schedule{
    public:
        Schedule()= default;
        // count the chosen part of the schedule
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        //insert item
        void InsertScheduleItem(const SchedulingItem &item);

        //checking methods
        size_t Size() const;
        SchedulingItem operator[](int number) const;

    private:
        std::vector <SchedulingItem> schedule_;



    };


    class Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots);

    };

    //GreedyScheduler //algorithm
}


#endif //JIMP_EXERCISES_SCHEDULER_H
