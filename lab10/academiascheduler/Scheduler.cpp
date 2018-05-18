//
// Created by kamila on 16.05.18.
//

#include "Scheduler.h"
#include <algorithm>

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule scheduleofteacher;
    for(auto i:schedule_){
        if (i.TeacherId()==teacher_id){
            scheduleofteacher.InsertScheduleItem(i);
        }
    }

/*std::transform(schedule_.begin(), schedule_.end(), std::back_inserter(scheduleofteacher.schedule_),
               [teacher_id](auto i){return teacher_id==i.TeacherId();});*/

return scheduleofteacher;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule scheduleofroom;
    for(auto i:schedule_){
        if (i.RoomId()==room_id){
            scheduleofroom.InsertScheduleItem(i);
        }
}

return scheduleofroom;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule scheduleofyear;
    for(auto i:schedule_){
        if (i.Year()==year){
            scheduleofyear.InsertScheduleItem(i);
    }
}

return scheduleofyear;
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector<int> takenslots;
    std::vector<int> freeslots;

    for(auto i:schedule_){
        takenslots.emplace_back(i.TimeSlot());
    }

    std::sort(takenslots.begin(),takenslots.end());
    auto last = std::unique(takenslots.begin(), takenslots.end());
    takenslots.erase(last,takenslots.end());

    int k=0;

    for (int j=1,k=0;j<=n_time_slots;j++){
        if(k<takenslots.size() && takenslots[k]==j){
            ++k;
        }
        else{
            freeslots.emplace_back(j);
        }
    }

    return freeslots;





}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    schedule_.emplace_back(item);
}

size_t academia::Schedule::Size() const {
    return schedule_.size();
}

academia::SchedulingItem academia::Schedule::operator[](int number) const {
    return schedule_[number];
}
