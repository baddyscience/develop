package com.cyx.pokemon.item;

import com.cyx.pokemon.DisplayItem;

public class Treasure implements DisplayItem {

    public Treasure(int levelNumber) {
        super("宝箱", levelNumber);
    }

    @Override
    public String getItemInformation() {
        return "■";
    }

}
