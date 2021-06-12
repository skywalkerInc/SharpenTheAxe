# Guitar Shop

## Requirements
* Different types of guitar should be available for sale
* Customer should be able to see price of guitar
* Availability of guitar should be shown to customer
* Guitar accessory should be shown for sale to customer
* Owner should be shown number of guitar available
* Owner should be notified if number of particular item is less than certain pieces.
* Show the branches of shop in city and country
* Sale summary should be sent to owner email

## Actors
* Customer
* Owner
* System

## UseCases
* Add Artifact(guitar/accessory) by owner
* Search guitar with filter by customer
* Add/Modify artifact price
* Add/Modify artifact quantity
* Set limit on minimum number of artifact for particular type of artifact by owner
* checkout artifact by customer
* notify owner if artifact is less than set limit
* generate report for sale


## Classes
* Shop
* Guitar
* Artifact (could be guitar or accessary)
* Search
* Report
* Notification


