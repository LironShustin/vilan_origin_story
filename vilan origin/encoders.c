#include "encoders.h"
#include "Structs&Enums.h"

int encode_drama_villain(drama_villain v) {
    return v.how_long_known * 10 + v.where_met;
}

int encode_comedy_villain(comedy_villain v) {
    return v.how_long_known * 10 + v.where_met;
}

int encode_fantasy_villain1(fantasy_villain1 v) {
    return v.meeting_place * 100 + v.same_side * 10 + v.how_long_sience_than;
}

int encode_fantasy_villain2(fantasy_villain2 v) {
    return v.meeting_place * 10 + v.crew_member;
}

int encode_scifi_villain1(scifi_villain1 v) {
    return v.meeting_place * 100 + v.same_side * 10 + v.how_long_sience_than;
}

int encode_scifi_villain2(scifi_villain2 v) {
    return v.meeting_place * 10 + v.crew_member;
}

int encode_thriller_villain1(thriller_villain1 v) {
    return v.did_they_meet * 100 + v.where * 10 + v.crew_member;
}

int encode_thriller_villain2(thriller_villain2 v) {
    return v.did_they_meet * 100 + v.where * 10 + v.hero_duty;
}

int encode_thriller_villain3(thriller_villain3 v) {
    return v.did_they_meet * 10 + v.hero_duty;
}
