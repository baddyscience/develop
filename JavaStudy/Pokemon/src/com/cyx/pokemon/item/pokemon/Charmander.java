package com.cyx.pokemon.item.pokemon;

/**
 * 小火龙
 */
public class Charmander extends Pokemon{

    public Charmander() {
        super("小火龙");
        this.attack = 100;
        this.defense = 80;
        this.health = 1000;
        this.currentHealth = this.health;
    }
}
