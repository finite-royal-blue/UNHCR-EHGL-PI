<?php
/**
 * @file
 * saved.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function saved_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function saved_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function saved_node_info() {
  $items = array(
    'audio_clips' => array(
      'name' => t('Audio clips'),
      'base' => 'node_content',
      'description' => t('Upload audio clips'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for content linked to a menu item such as the welcome guide, administrative procedures, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page_top_article' => array(
      'name' => t('Page top Article'),
      'base' => 'node_content',
      'description' => t('TOp Articles on a page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'regional_news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('Add news worthy articles.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
