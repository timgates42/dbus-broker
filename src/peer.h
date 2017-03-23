#pragma once

/*
 * Peers
 */

#include <c-macro.h>
#include <c-rbtree.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct Bus Bus;
typedef struct Peer Peer;
typedef struct UserEntry UserEntry;

struct Peer {
        UserEntry *user;
        CRBTree names;
        CRBNode rb;
        uint64_t id;
};

int peer_new(Bus *bus, Peer **peerp, uid_t uid);
Peer *peer_free(Peer *peer);

C_DEFINE_CLEANUP(Peer *, peer_free);
