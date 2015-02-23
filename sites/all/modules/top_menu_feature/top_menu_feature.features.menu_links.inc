<?php
/**
 * @file
 * top_menu_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function top_menu_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-top-menu_about-us:about_eha/
  $menu_links['menu-top-menu_about-us:about_eha/'] = array(
    'menu_name' => 'menu-top-menu',
    'link_path' => 'about_eha/',
    'router_path' => 'about_eha',
    'link_title' => 'About Us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-top-menu_about-us:about_eha/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-top-menu_news-and-views:new_and_views/
  $menu_links['menu-top-menu_news-and-views:new_and_views/'] = array(
    'menu_name' => 'menu-top-menu',
    'link_path' => 'new_and_views/',
    'router_path' => 'new_and_views',
    'link_title' => 'News and Views',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-top-menu_news-and-views:new_and_views/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-top-menu_what-we-do:what_we_do/
  $menu_links['menu-top-menu_what-we-do:what_we_do/'] = array(
    'menu_name' => 'menu-top-menu',
    'link_path' => 'what_we_do/',
    'router_path' => 'what_we_do',
    'link_title' => 'What We Do',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-top-menu_what-we-do:what_we_do/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-top-menu_where-we-work:where_we_work/
  $menu_links['menu-top-menu_where-we-work:where_we_work/'] = array(
    'menu_name' => 'menu-top-menu',
    'link_path' => 'where_we_work/',
    'router_path' => 'where_we_work',
    'link_title' => 'Where We Work',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-top-menu_where-we-work:where_we_work/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-top-menu_who-we-help:who_we_help/
  $menu_links['menu-top-menu_who-we-help:who_we_help/'] = array(
    'menu_name' => 'menu-top-menu',
    'link_path' => 'who_we_help/',
    'router_path' => 'who_we_help',
    'link_title' => 'Who We Help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-top-menu_who-we-help:who_we_help/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About Us');
  t('News and Views');
  t('What We Do');
  t('Where We Work');
  t('Who We Help');


  return $menu_links;
}
