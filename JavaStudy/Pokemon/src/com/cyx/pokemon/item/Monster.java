package com.cyx.pokemon.item;

import com.cyx.pokemon.DisplayItem;

public class Monster implements DisplayItem {

    public Monster(String name, int levelNumber) {
        super(name, levelNumber);
    }

    @Override
    public String getItemInformation() {
        return "■";
    }

}
