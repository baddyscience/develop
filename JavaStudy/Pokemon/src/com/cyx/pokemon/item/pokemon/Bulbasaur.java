package com.cyx.pokemon.item.pokemon;

/**
 * 妙蛙种子
 */
public class Bulbasaur extends Pokemon{

    public Bulbasaur() {
        super("妙蛙种子");
        this.attack = 60;
        this.defense = 40;
        this.health = 600;
        this.currentHealth = this.health;
    }
}
