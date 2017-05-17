class TravelAlert {
    int id;
    int locationId;
    string message;
}

class Location {
    int locationId;
    int parentLocationId; // -1 if no parent, location is hierarchy
    string name;

    static Location findLocation(int locationId){

    }
}

class TravelAlertStore {
private:
    list<TravelAlert> lAlerts;
public:
    TravelAlert findBestTravelAlert(int locationId) { // Return null if no alert
        map<int, TravelAlert> mapping;
        for(int i = 0; i < lAlerts.size(); i++){
            TravelAlert alert = lAlerts[i];
            map[alert.locationId] = alert;
        }

        while(locationId > 0){
            if(mapping.find(locationId) != mapping.end())
                return mapping[locationId]
            locationId = Location.findLocation(locationId).parentLocationId;
        }

        return NULL;
    }
}
