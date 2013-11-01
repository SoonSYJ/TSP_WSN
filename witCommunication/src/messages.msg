
message myPosition {
    int srcNodeID;
	int destinationNodeID;
	int nodeID;
	int x;
	int y;
}

message ImYourMaster
{
	int srcNodeID;
	int destinationNodeID;
}

message ImYourSlave
{
	int srcNodeID;
	int destinationNodeID;
}
message SyncMsg
{
	int srcNodeID;
	int destinationNodeID;
}
message FollowUp
{
	int srcNodeID;
	simtime_t timeMoment;
	int destinationNodeID;
}
message DelayReq
{
	int srcNodeID;
	int destinationNodeID;
}
message DelayResp
{
	int srcNodeID;
	int destinationNodeID;
	simtime_t timeMoment;
}
