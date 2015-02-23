<?php
/**
 * @file
 * saved.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function saved_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about-us:about_eha/
  $menu_links['main-menu_about-us:about_eha/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'about_eha/',
    'router_path' => 'about_eha',
    'link_title' => 'About Us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_about-us:about_eha/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_governance-and-organization:node/1704
  $menu_links['main-menu_governance-and-organization:node/1704'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1704',
    'router_path' => 'node/%',
    'link_title' => 'Governance and Organization',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_governance-and-organization:node/1704',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about-us:about_eha/',
  );
  // Exported menu link: main-menu_history-of-unhcr:node/1703
  $menu_links['main-menu_history-of-unhcr:node/1703'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1703',
    'router_path' => 'node/%',
    'link_title' => 'History of UNHCR',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_history-of-unhcr:node/1703',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_about-us:about_eha/',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About Us');
  t('Governance and Organization');
  t('History of UNHCR');


  return $menu_links;
}
