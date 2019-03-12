Geokosa server
============================


DIRECTORY STRUCTURE
-------------------

      EthernetUDP/      contains all source files (*.h and *.cpp)
      

REQUIREMENTS
------------

The minimum requirement by this project template that your platform supports Postgresql (10.0+) 
(see https://postgrespro.ru/docs/) and boost.Container (1.68).


INSTALLATION
------------

### Install from an Archive File

1.Clone project from repository, using command:

    git clone http://git.fitos.org/seismic_server.git


3.Install required libraries (boost):

    #sudo aptitude install libboost-all-dev


CONFIGURATION
-------------
### Boost
    You should add to the *.pro file of QtCreator 
    [LIBS += \
       -lboost_system\]
    to start working with boost::circle_buffer


### Database

Create in Postgresql the db table to work with application:

```php
return [
    CREATE TABLE public.counts
(
      id integer NOT NULL GENERATED BY DEFAULT AS IDENTITY primary key,
      timestamp_uts integer NOT NULL,
      chanel_id integer NOT NULL,
      sensor_id integer NOT NULL,
      value double precision NOT NULL
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.counts
      OWNER to postgres;
      
      ======================

      Example:
insert into counts (timestamp_uts, chanel_id, sensor_id, value) values
(23, 1, 1, 42.7),
(14, 2, 2, 63.2)
];
```

**NOTES:**
- 
- 
- 
# UdpStreamServer