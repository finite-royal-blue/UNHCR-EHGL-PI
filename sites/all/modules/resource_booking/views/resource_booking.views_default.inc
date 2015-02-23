<?php

/**
 * @file
 * Provides default views
 */

/**
 * Implements hook_views_default_views().
 */
function resource_booking_views_default_views() {
  $views = array();
  _resource_booking_views_resource_schedule($views);
  _resource_booking_views_resource_for_approval($views);
  return $views;
}

/**
 * Default view for showing resources that are awaiting approval
 */
function _resource_booking_views_resource_for_approval(&$views) {
  if (!module_exists('views_bulk_operations')) {
    drupal_set_message(t('Views Bulk Operations module is required for %view view to work.',
      array('%view' => t('Resources pending approval'))), 'error');
  }
  $view = new view;
  $view->name = 'resource_approval';
  $view->description = '';
  $view->tag = 'Resources Booking';
  $view->base_table = 'node';
  $view->human_name = 'Resources pending approval';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Resources for approval';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'change resource status';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Resource Booking: Resource */
  $handler->display->display_options['relationships']['field_ge_resources_nid']['id'] = 'field_ge_resources_nid';
  $handler->display->display_options['relationships']['field_ge_resources_nid']['table'] = 'field_data_field_ge_resources';
  $handler->display->display_options['relationships']['field_ge_resources_nid']['field'] = 'field_ge_resources_nid';
  $handler->display->display_options['relationships']['field_ge_resources_nid']['required'] = 0;
  /* Field: Content: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'resource_booking_status_approve_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'resource_booking_status_decline_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Event';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_ge_resources_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Resource';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Resource Booking: Booking status */
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['id'] = 'field_ge_resources_rb_status';
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['table'] = 'field_data_field_ge_resources';
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['field'] = 'field_ge_resources_rb_status';
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ge_resources_rb_status']['hide_alter_empty'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'great_events' => 'great_events',
    'laptop_booking' => 'laptop_booking',
    'room_bookings' => 'room_bookings',
  );
  /* Filter criterion: Resource Booking: Booking status */
  $handler->display->display_options['filters']['field_ge_resources_rb_status']['id'] = 'field_ge_resources_rb_status';
  $handler->display->display_options['filters']['field_ge_resources_rb_status']['table'] = 'field_data_field_ge_resources';
  $handler->display->display_options['filters']['field_ge_resources_rb_status']['field'] = 'field_ge_resources_rb_status';
  $handler->display->display_options['filters']['field_ge_resources_rb_status']['value'] = array(
    'r' => 'r',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'resource-requested';

  /////INSERT BEFORE THIS LINE/////
  $views['resource_approval'] = $view;
}

/**
 * Default view for showing schedule of resources
 */
function _resource_booking_views_resource_schedule(&$views) {
  $view = new view;
  $view->name = 'calendar_of_resource_booking';
  $view->description = 'A multi-dimensional calendar view with back/next navigation.';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Calendar of Resource Booking';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'calendar';
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['pager_position'] = 'top';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'resource_booking_calendar_node';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'greatest_events' => '#ffffff',
    'resources' => '#ffffff',
    'simple_events' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    2 => 0,
    1 => 0,
  );
  /* Relationship: Resource Booking: Resource */
  $handler->display->display_options['relationships']['field_01234567890123456789012345_nid']['id'] = 'field_01234567890123456789012345_nid';
  $handler->display->display_options['relationships']['field_01234567890123456789012345_nid']['table'] = 'field_data_field_01234567890123456789012345';
  $handler->display->display_options['relationships']['field_01234567890123456789012345_nid']['field'] = 'field_01234567890123456789012345_nid';
  $handler->display->display_options['relationships']['field_01234567890123456789012345_nid']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_01234567890123456789012345_nid';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Resource Booking: End date */
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['id'] = 'field_01234567890123456789012345_edate';
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['table'] = 'field_data_field_01234567890123456789012345';
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['field'] = 'field_01234567890123456789012345_edate';
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_edate']['date_format'] = 'long';
  /* Field: Resource Booking: Start date */
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['id'] = 'field_01234567890123456789012345_sdate';
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['table'] = 'field_data_field_01234567890123456789012345';
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['field'] = 'field_01234567890123456789012345_sdate';
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_sdate']['date_format'] = 'long';
  /* Field: Resource Booking: Resource NID */
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['id'] = 'field_01234567890123456789012345_nid';
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['table'] = 'field_data_field_01234567890123456789012345';
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['field'] = 'field_01234567890123456789012345_nid';
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_01234567890123456789012345_nid']['hide_alter_empty'] = 0;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_01234567890123456789012345.field_01234567890123456789012345_sdate' => 'field_data_field_01234567890123456789012345.field_01234567890123456789012345_sdate',
  );
  /* Contextual filter: Resource Booking: Resource NID */
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['id'] = 'field_01234567890123456789012345_nid';
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['table'] = 'field_data_field_01234567890123456789012345';
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['field'] = 'field_01234567890123456789012345_nid';
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_01234567890123456789012345_nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'great_events' => 'great_events',
  );

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['pager_position'] = 'top';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'resource_booking_calendar_node';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'greatest_events' => '#ffffff',
    'resources' => '#ffffff',
    'simple_events' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    2 => 0,
    1 => 0,
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'rs-calendar/month';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Month';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['pager_position'] = 'top';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'resource_booking_calendar_node';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'greatest_events' => '#ffffff',
    'resources' => '#ffffff',
    'simple_events' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    2 => 0,
    1 => 0,
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'rs-calendar/week';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '2';

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['pager_position'] = 'top';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'resource_booking_calendar_node';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'greatest_events' => '#ffffff',
    'resources' => '#ffffff',
    'simple_events' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    2 => 0,
    1 => 0,
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'rs-calendar/day';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['pager_position'] = 'top';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'resource_booking_calendar_node';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'greatest_events' => '#ffffff',
    'resources' => '#ffffff',
    'simple_events' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    2 => 0,
    1 => 0,
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'rs-calendar/year';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';

  /////INSERT BEFORE THIS LINE/////
  $views['resource_schedule'] = $view;
}

function _resource_booking_views_resource_schedule_calendar_v2(&$views) {
  $view = new view;
  $view->name = 'resource_schedule';
  $view->description = 'Calendar view of resource usage';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Resource schedule';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Calendar';
  $handler->display->display_options['items_per_page'] = 0;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access resource scheduling';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'calendar_nav';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Resource Booking: Start date */
  $handler->display->display_options['fields']['field_res_sdate']['id'] = 'field_res_sdate';
  $handler->display->display_options['fields']['field_res_sdate']['table'] = 'field_data_field_res';
  $handler->display->display_options['fields']['field_res_sdate']['field'] = 'field_res_sdate';
  $handler->display->display_options['fields']['field_res_sdate']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_res_sdate']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_res_sdate']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_res_sdate']['date_format'] = 'long';
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['value'] = 'All';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['year_range'] = '-3:+3';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'month';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_res.field_res_sdate' => 'field_data_field_res.field_res_sdate',
  );
  $handler->display->display_options['arguments']['date_argument']['date_method'] = 'OR';
  $handler->display->display_options['arguments']['date_argument']['date_group'] = 'date';
  /* Contextual filter: Resource Booking: Resource NID */
  $handler->display->display_options['arguments']['field_res_nid']['id'] = 'field_res_nid';
  $handler->display->display_options['arguments']['field_res_nid']['table'] = 'field_data_field_res';
  $handler->display->display_options['arguments']['field_res_nid']['field'] = 'field_res_nid';
  $handler->display->display_options['arguments']['field_res_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_res_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_res_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_res_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_res_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_res_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_res_nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'my_events' => 'my_events',
  );

  /* Display: Calendar page */
  $handler = $view->new_display('calendar', 'Calendar page', 'calendar_1');
  $handler->display->display_options['items_per_page'] = 0;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'calendar_nav';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['path'] = 'resource-booking-calendar';

  /* Display: Calendar block */
  $handler = $view->new_display('calendar_block', 'Calendar block', 'calendar_block_1');
  $handler->display->display_options['items_per_page'] = 0;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'calendar_nav';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Calendar';

  /* Display: Year view */
  $handler = $view->new_display('calendar_period', 'Year view', 'calendar_period_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['max_items_behavior'] = 'more';
  $handler->display->display_options['style_options']['groupby_times'] = 'hour';
  $handler->display->display_options['style_options']['groupby_times_custom'] = '';
  $handler->display->display_options['style_options']['groupby_field'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'calendar_1' => 'calendar_1',
    'default' => 0,
    'calendar_block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: Month view */
  $handler = $view->new_display('calendar_period', 'Month view', 'calendar_period_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['max_items_behavior'] = 'more';
  $handler->display->display_options['style_options']['groupby_times'] = 'hour';
  $handler->display->display_options['style_options']['groupby_times_custom'] = '';
  $handler->display->display_options['style_options']['groupby_field'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'calendar_1' => 'calendar_1',
    'default' => 0,
    'calendar_block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: Day view */
  $handler = $view->new_display('calendar_period', 'Day view', 'calendar_period_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['max_items_behavior'] = 'more';
  $handler->display->display_options['style_options']['groupby_times'] = 'hour';
  $handler->display->display_options['style_options']['groupby_times_custom'] = '';
  $handler->display->display_options['style_options']['groupby_field'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'calendar_1' => 'calendar_1',
    'default' => 0,
    'calendar_block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: Week view */
  $handler = $view->new_display('calendar_period', 'Week view', 'calendar_period_4');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['max_items_behavior'] = 'more';
  $handler->display->display_options['style_options']['groupby_times'] = 'hour';
  $handler->display->display_options['style_options']['groupby_times_custom'] = '';
  $handler->display->display_options['style_options']['groupby_field'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'calendar_1' => 'calendar_1',
    'default' => 0,
    'calendar_block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: Block view */
  $handler = $view->new_display('calendar_period', 'Block view', 'calendar_period_5');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['max_items_behavior'] = 'more';
  $handler->display->display_options['style_options']['groupby_times'] = 'hour';
  $handler->display->display_options['style_options']['groupby_times_custom'] = '';
  $handler->display->display_options['style_options']['groupby_field'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'calendar_1' => 0,
    'default' => 0,
    'calendar_block_1' => 'calendar_block_1',
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'day';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['default_to_date'] = '';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-1:+1';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.changed' => 'node.changed',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'OR';
  $handler->display->display_options['filters']['date_filter']['date_group'] = 'date';
  $handler->display->display_options['block_description'] = 'Upcoming';

  /////INSERT BEFORE THIS LINE/////
  $views['resource_schedule'] = $view;
}
