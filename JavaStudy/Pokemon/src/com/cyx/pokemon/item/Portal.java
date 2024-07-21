package com.cyx.pokemon.item;

import com.cyx.pokemon.DisplayItem;

public class Portal implements DisplayItem {
    /**
     * 是否是通往下一关卡的传送门
     */
    private boolean next;
    public Portal(boolean next) {
        super("传送门");
        this.next = next;
    }

    @Override
    public String getItemInformation() {
        return "■";
    }
}
