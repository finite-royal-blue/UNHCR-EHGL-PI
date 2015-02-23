<?php
/**
 * @file
 * news_ct_feature.features.inc
 */

/**
 * Implements hook_node_info().
 */
function news_ct_feature_node_info() {
  $items = array(
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
