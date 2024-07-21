package com.cyx.pokemon.item;

import com.cyx.pokemon.DisplayItem;

/**
 * 传送门
 */
public class Portal extends Item {
    /**
     * 是否是通往下一关卡的传送门
     */
    private boolean next;

    public Portal(boolean next) {
        super("传送门");
        this.next = next;
    }

    public boolean isNext() {
        return next;
    }

    @Override
    public String getItemInformation() {
        if(discovery){
            return next ? "→" : "←";
        }
        return "■";
    }
}
