#define MAXNBNODES 255
#define NBDIRECTIONS 2
#define MAXNBCHILDS 30
#define SERVER_ADDRESS 1000
#define FIFO_BUFFER_SIZE 500
#define MAP_X_SIZE 50
#define MAP_Y_SIZE 50
#define LOCATION_CHANGE_PERIOD 500

/*The time elapsed between sending SYNC and followUP
 * This constant do NOT effect the precision*/
#define SYNC_FOLLOW_UP_DIFF 1

/* The time elapsed between receiving FollowUp and sending DelayReq
 * if the offset is linear function, this variable will have HIGH
 * effect on the precision of the algorithm */
#define FOLLOW_UP_DELAY_REQ_DIFF 10
/* The time elapsed between two time synchronizations */
#define SYNC_PERIOD 1000
typedef struct
{
    int adress;
}adress_type;
