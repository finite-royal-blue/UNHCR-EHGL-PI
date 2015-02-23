<?php
/**
 * @file
 * saved.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function saved_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_news_theme|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_news_theme';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_th_news_protection',
        1 => 'field_th_news_assistance',
      ),
      'right' => array(
        2 => 'field_th_news_op_supt',
        3 => 'field_th_news_dur_solts',
      ),
    ),
    'fields' => array(
      'field_th_news_protection' => 'left',
      'field_th_news_assistance' => 'left',
      'field_th_news_op_supt' => 'right',
      'field_th_news_dur_solts' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_news_theme|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_news_theme|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_news_theme';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_th_news_protection',
        1 => 'field_th_news_assistance',
      ),
      'right' => array(
        2 => 'group_test_ds_grp',
        3 => 'field_th_news_op_supt',
        4 => 'field_th_news_dur_solts',
      ),
      'hidden' => array(
        5 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_th_news_protection' => 'left',
      'field_th_news_assistance' => 'left',
      'group_test_ds_grp' => 'right',
      'field_th_news_op_supt' => 'right',
      'field_th_news_dur_solts' => 'right',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_news_theme|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page_top_article|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page_top_article';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_artcle_top_picture',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'field_artcle_top_picture' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|page_top_article|default'] = $ds_layout;

  return $export;
}
