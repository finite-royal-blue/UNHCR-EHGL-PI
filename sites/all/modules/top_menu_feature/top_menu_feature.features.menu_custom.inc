<?php
/**
 * @file
 * top_menu_feature.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function top_menu_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-top-menu.
  $menus['menu-top-menu'] = array(
    'menu_name' => 'menu-top-menu',
    'title' => 'Top Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Top Menu');


  return $menus;
}
