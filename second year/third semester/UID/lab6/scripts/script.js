
Array.prototype.remove = function(value) {
    var idx = this.indexOf(value);
    if (idx != -1) return this.splice(idx, 1);
    return false;
}

function getShuffledDeck() {
    var deck = [];
    var suits = ["S", "C", "D", "H"];
    suits.forEach(function(suit) {
        for (let i = 1; i <= 9; i++)
            deck.push(i+suit);    
    });
    for (let i = deck.length; i; i--) {
        let j = Math.floor(Math.random() * i);
        [deck[i - 1], deck[j]] = [deck[j], deck[i - 1]];
    }
    return deck;
}

var shuffledDeck = getShuffledDeck();
var model = {
    isPlayerTurn: !!Math.floor(Math.random()*2),
    beaten: true,
    opponentTakes: false,
    deck: shuffledDeck.slice(0, 24),
    trump: shuffledDeck[0],
    playerHand: shuffledDeck.slice(30, 36),
    opponentHand: shuffledDeck.slice(24, 30),
    attack: [],
    defend: [],
}

var durakApp = angular.module("durak", []);


durakApp.controller("durakCtrl", function($scope) {

    $scope.clickCard = function($event) {

        if ($scope.data.attack.length >= 6) return;
        var card = $event.currentTarget.id;

        if ($scope.data.isPlayerTurn && $scope.data.beaten) {

            //check is card correct
            if ($scope.data.attack.length == 0 || isSameCardOnTable(card)) {
                $scope.data.attack.push(card);
                $scope.data.playerHand.remove(card);
                $scope.data.beaten = false;

                //next state
                if (!$scope.data.opponentTakes) {
                    setTimeout($scope.opponentDefend, 500);
                }
            }
        } else { //player defends

            attackCard = String($scope.data.attack.slice(-1));

            //check is card correct
            if (card[1] == attackCard[1] && card[0] > attackCard[0] || 
                card[1] == $scope.data.trump[1] && attackCard[1] != card[1]) {
                $scope.data.defend.push(card);
                $scope.data.playerHand.remove(card);
                setTimeout($scope.opponentAttack, 500);
            }
        }
    }


    $scope.clickLetTake = function($event) {

        //replace cards to opponent hand
        $scope.data.attack.forEach(function(el) {
            $scope.data.opponentHand.push(el);
        });
        $scope.data.defend.forEach(function(el) {
            $scope.data.opponentHand.push(el);
        });
        $scope.data.attack = [];
        $scope.data.defend = [];

        //next state
        $scope.data.opponentTakes = false;
        $scope.data.beaten = true;
        $scope.giveCards();
        $scope.data.isPlayerTurn = true;
    }


    $scope.opponentDefend = function() {

        var card = String($scope.data.attack.slice(-1));
        var chosenCard;

        //search correct card
        $scope.data.opponentHand.forEach(function(el) {
            //is card correct
            if ((el[0] > card[0]) && (el[1] == card[1]) ||
                 (el[1] == $scope.data.trump[1] && card[1] != el[1])) {

                if (!chosenCard) chosenCard = el;

                //is card better than current card
                if (el[0] < chosenCard[0] && el[1] == chosenCard[1] 
                    || chosenCard[1] == $scope.data.trump[1] && el[1] != chosenCard[1])
                    chosenCard = el;
            }   
        });

        //next state
        if (chosenCard) {
            $scope.data.defend.push(chosenCard);
            $scope.data.opponentHand.remove(chosenCard);
            $scope.data.beaten = true;
        } else
            $scope.data.opponentTakes = true;
        $scope.$apply();
    }

    $scope.giveCards = function() {
        while(($scope.data.playerHand.length < 6 || $scope.data.opponentHand.length < 6) && $scope.data.deck.length > 0) {
            if ($scope.data.playerHand.length < 6 && $scope.data.deck.length > 0) {
                $scope.data.playerHand.push(String($scope.data.deck.slice(-1)));
                $scope.data.deck.splice(-1, 1);
            }
            if ($scope.data.opponentHand.length < 6 && $scope.data.deck.length > 0) {
                $scope.data.opponentHand.push(String($scope.data.deck.slice(-1)));
                $scope.data.deck.splice(-1, 1);
            }
        }
    }

    function isSameCardOnTable(card) {
        var valid = false;
        $scope.data.attack.forEach(function(el) {
            if (card[0] == el[0])
                valid = true;
        });
        $scope.data.defend.forEach(function(el) {
            if (card[0] == el[0])
                valid = true;
        });
        return valid;
    }

    $scope.opponentAttack = function() {

        var chosenCard;

        //if table is empty
        if ($scope.data.attack.length == 0) {

            //search optimal card
            chosenCard = $scope.data.opponentHand[0];
            $scope.data.opponentHand.forEach(function(el) {
                if (el[0] < chosenCard[0] && el[1] == chosenCard[1] || 
                    chosenCard[1] == $scope.data.trump[1] && el[1] != chosenCard[1])
                    chosenCard = el;
            });

        } else {
            if ($scope.data.attack.length < 6) {
                $scope.data.opponentHand.forEach(function(el) {
                    if(isSameCardOnTable(el)) chosenCard = el;
                });
            }
        }

        if (chosenCard) {
            $scope.data.attack.push(chosenCard);
            $scope.data.opponentHand.remove(chosenCard);
            $scope.data.beaten = false;
        } else {
            $scope.data.attack = [];
            $scope.data.defend = [];
            $scope.giveCards();
            $scope.data.isPlayerTurn = true;
            $scope.data.beaten = true;
        }
        $scope.$apply();
    }

    $scope.endTurn = function($event) {
        $scope.data.attack = [];
        $scope.data.defend = [];
        $scope.data.isPlayerTurn = false;
        $scope.giveCards();
        setTimeout($scope.opponentAttack, 500);
    }

    $scope.take = function($event) {
        //replace cards to player hand
        $scope.data.attack.forEach(function(el) {
            $scope.data.playerHand.push(el);
        });
        $scope.data.defend.forEach(function(el) {
            $scope.data.playerHand.push(el);
        });
        $scope.data.attack = [];
        $scope.data.defend = [];

        //next state
        $scope.giveCards();
        setTimeout($scope.opponentAttack, 500);
        $scope.apply();

    }

    $scope.playAgain = function() {
        location.reload();
    }

    $scope.data = model;
    if (!$scope.data.isPlayerTurn) setTimeout($scope.opponentAttack, 500);

});