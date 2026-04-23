male(jack).
male(chris).
male(robert).
male(donald).
male(james).
male(george).
male(william).
male(john).
female(jenny).
female(melinda).
female(wynona).
female(ella).
female(lydia).
female(erica).
female(leah).
female(sydney).
spouse(jack, jenny).
spouse(jenny, jack).
spouse(donald, ella).
spouse(ella, donald).
spouse(chris, melinda).
spouse(melinda, chris).
spouse(robert, wynona).
spouse(wynona, robert).
spouse(james, lydia).
spouse(lydia, james).
%family of jack and jenny, and chris and robert are their children.
parent(jack,chris).
parent(jenny,chris).
parent(jack, robert).
parent(jenny, robert).
%family of donald and ella, melinda and james are their children.
parent(donald, melinda).
parent(ella, melinda).
parent(donald, james).
parent(ella, james).
%family of melinda and chris, george and sydney are their children.
parent(chris, george).
parent(melinda, george).
parent(chris, sydney).
parent(melinda, sydney).
%family of robert and wynona, william is their child.
parent(robert, william).
parent(wynona, william).
%family of james and lydia, john is their child.
parent(james, john).
parent(lydia, john).
%rules for our family.
father(F,C) :- 
    parent(F,C),
    male(M).
mother(M, C) :-
    parent(M, C),
    female(M).
sibling(A, B) :-
    parent(P, A),
    parent(P, B),
    A \= B. 
brother(B, C) :-
    sibling(B, C),
    male(B).
sister(S, C) :-
    sibling(S, C),
    female(S).
grandparent(GP, C) :-
    parent(GP, P),
    parent(P, C).
grandchild(C, GP) :-
    grandparent(GP, C).
uncle(U, N) :-
    sibling(U, P),
    parent(P, N),
    male(U).
aunt(A, N) :-
    sibling(A, P),
    parent(P, N),
    female(A).
cousin(A, B) :-
    parent(P1, A),
    parent(P2, B),
    sibling(P1, P2),
    A \= B.
ancestor(A, D) :-
    parent(A, D).
ancestor(A, D) :-
    parent(A, X),
    ancestor(X, D).
married(X, Y) :-
    spouse(X, Y).